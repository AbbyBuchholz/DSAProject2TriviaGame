const express = require("express");
const { exec } = require("child_process");
const cors = require("cors");
const path = require("path");

const app = express();
app.use(cors());
app.use(express.json());

const exePath = path.join(__dirname, "main.exe");

exec(`g++ "${path.join(__dirname, "main.cpp")}" -o "${exePath}"`, (err, stdout, stderr) => {
    if (err) {
        console.error("Compilation error:", stderr);
    } else {
        console.log("main.cpp compiled successfully!");
    }
});

app.get("/random", (req, res) => {
    exec(`"${exePath}"`, (err, stdout, stderr) => {
        if (err) return res.json({ error: stderr.trim() });
        res.json({ number: stdout.trim() });
    });
});

app.listen(5000, () => console.log("Server running on http://localhost:5000"));
