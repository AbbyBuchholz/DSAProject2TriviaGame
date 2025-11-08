import { useState, useEffect} from 'react'
import './App.css'

function App() {
    const categories = ["Books", "Movies", "Songs", "Cities"];
    const categoryColor = ['#C28686', '#C5B885', '#C78FB4', '#8CC084'];

  const [selected, setSelected] = useState(Array(categories.length).fill(true));
  const [randomItem, setRandomItem] = useState("Click Next!");
    const [randomColor, setRandomColor] = useState('white');

    const[question, setQuestion] = useState("");
    const[answer, setAnswer] = useState("");
    const[userAnswer, setUserAnswer] = useState("");
    const[points, setPoints] = useState(0);

    const toggleBox = (index) => {
        setSelected((prev) =>{
            const updated = [...prev];
            let falseCount = updated.filter(item => item === false).length;
            //console.log(falseCount, updated[index]);
            if (falseCount < 3 || updated[index] === false) {
                updated[index] = !updated[index];
            }
            return updated;
        });
    };

    const pickRandomItem = async () => {
        try{
            const res = await fetch("http://localhost:5000/random", {
            method: "POST",
            headers: {"Content-Type" : "application/json"},
            body: JSON.stringify({userInput: "next"}),
        });
            const data = await res.json();
            console.log("Response data:", data);
            setQuestion(data.question || "Got questions! Click Next to begin!");
            setAnswer(data.answer);
            if (data.question && data.category) {
                setQuestion(data.question);

                const catIndex = categories.findIndex(cat => cat === data.category);

                if (catIndex !== -1) {
                    setRandomItem(categories[catIndex]);
                    setRandomColor(categoryColor[catIndex]);
                }
            }
        } catch (err){
            setQuestion("Couldn't find a question!");
        }
        document.getElementById("guess").disabled = false;
    };

    const answering = () => {
        if (userAnswer == answer && answer != ""){
            setPoints(points+1);
            setUserAnswer("");
            document.getElementById("guess").disabled = true;
        }
    };
  return (
      <>
          <div id="app">
          <header>
              <h1>Trivia Game!</h1>
              <h5>Made by Abby Buchholz, Sophia Pappous, and Adam Jarvis</h5>
          </header>
              <div id="mainBlock">
          <main>
              <div id="topBar">
              <span>Category:</span>
                  {randomItem && randomColor && <div id="categoryDisplay" style={{backgroundColor: randomColor}}>{randomItem}</div>}
                  <span>
              <p>Points:</p>
              <p>{points}</p>
                  </span>
              </div>
              <div id="question">
                  <p>{question}</p>
              </div>
              <div id="guessingArea">
                  <p>Guess:</p>
                  <input id="guess" type="text" placeholder="Type here..." value={userAnswer} onChange={(e) => setUserAnswer(e.target.value)}/>
                  <label className="buttonBar">
                      <button onClick={answering} className="buttonGuess"></button>
                      <span>Submit</span>
                  </label>
                  <label className="buttonBar">
                      <button onClick={pickRandomItem} className="buttonGuess"></button>
                      <span>Next</span>
                  </label>
              </div>
          </main>
              <aside>
                  <h3>Settings</h3>
                  <p>Sorting Algorithms:</p>
                  <div className="flexBox">
                      <div className="flexItem">
                          <label className="switch">
                              <input type="checkbox"/>
                              <span className="slider round"></span>
                          </label>
                          <span id="toggle-text">Merge Sort</span>
                      </div>
                      <div className="flexItem">
                          <label className="switch">
                              <input type="checkbox"/>
                              <span className="slider round"></span>
                          </label>
                          <span id="toggle-text">Heap Sort</span>
                      </div>
                  </div>
                      <div id="buttonsAside">
                      <label className="buttonBar">
                          <button className="buttonGuess"></button>
                          <span>Sort</span>
                      </label>
                      <label className="buttonBar">
                          <button onClick={() => handleClick("randomize")} className="buttonGuess"></button>
                          <span>Randomize</span>
                      </label>
                      </div>
                  <p>Select categories:</p>
                  <div className="multiselect">
                      <label className="toggle"><input type="checkbox" checked={selected[0]}
                                                       onChange={() => toggleBox(0)}/>
                          <span className="toggle-box">Books</span></label>
                      <label className="toggle"><input type="checkbox" checked={selected[1]}
                                                       onChange={() => toggleBox(1)}/>
                          <span className="toggle-box"> Movies</span></label>
                      <label className="toggle"><input type="checkbox" checked={selected[2]}
                                                       onChange={() => toggleBox(2)}/>
                          <span className="toggle-box"> Songs</span></label>
                      <label className="toggle"><input type="checkbox" checked={selected[3]}
                                                       onChange={() => toggleBox(3)}/>
                          <span className="toggle-box"> Cities</span></label>
                  </div>


                  <p>Special Categorization:</p>

                  <select name="verb" id="verb">
                      <option value="Before">Before</option>
                      <option value="After">After</option>
                      <option value="Only">Only</option>
                  </select>
                  <input type="number" min="0" max="2025"/>
              </aside>
                </div>
          </div>
      </>
  )
}

export default App
