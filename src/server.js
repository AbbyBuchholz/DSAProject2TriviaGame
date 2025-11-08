const express = require("express"); //use express from node
const { spawn } = require("child_process"); // allows the display
const cors = require("cors"); // allows the browser to like it
const path = require("path");

const app = express();
app.use(cors());
app.use(express.json());

const exePath = path.join(__dirname, "main.exe");
const cppPath = path.join(__dirname, "main.cpp");

const projectRoot = path.join(__dirname, "..");

const bridgesInclude = path.join(projectRoot, "libraries", "bridges", "include");
const bridgesLib = path.join(projectRoot, "libraries", "bridges", "lib");
const curlInclude = path.join(projectRoot, "libraries", "curl", "include");
const curlLib = path.join(projectRoot, "libraries", "curl", "lib");

const compileCommand = `g++ "${cppPath}" -o "${exePath}" -std=c++14 -I"${bridgesInclude}" -I"${bridgesLib}" -I"${curlInclude}" -L"${curlLib}" -lcurl`;
//this nonsense allows it to compile only once, thus saving time

const { exec } = require("child_process");
exec(compileCommand, (err, stdout, stderr) => {
    if (err) {
        console.error("Compilation error:", stderr);
    } else {
        console.log("main.cpp compiled successfully!");
    }
});

app.post("/random", (req, res) => {
    const userInput = req.body.userInput || "";

    const child = spawn(exePath, [userInput], { cwd: path.dirname(exePath) });

    let output = "";
    let error = "";

    child.stdout.on("data", (data) => {
        output += data.toString();
    });

    child.stderr.on("data", (data) => {
        error += data.toString();
    });

    child.on("close", (code) => {
        if (code !== 0) {
            console.error("Execution Error:", error);
            return res.status(500).json({ error: error.trim() || `Exited with code ${code}` });
        }

        //formats data
        const [question, answer, ...rest] = output.split("|");
        const category = rest.join("|").trim();
        res.json({
            question: question?.trim() || "",
            answer: answer?.trim() || "",
            category: category || ""
        });
    });
});

app.listen(5000, () => console.log("Server running on http://localhost:5000"));
