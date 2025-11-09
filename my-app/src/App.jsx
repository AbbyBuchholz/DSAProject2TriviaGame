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
    const[correct, setCorrect] = useState("");
    const [counter, setCounter] = useState(0);

    const toggleBox = (index) => {
        setSelected((prev) =>{
            const updated = [...prev];
            const trueCount = updated.filter((item) => item === true).length;
            //console.log(falseCount, updated[index]);
            if (updated[index] && trueCount === 1) {
                return prev;
            }
            updated[index] = !updated[index];
            return updated;
        });
    };

    const pickRandomItem = async (userInput = "next") => {
        try{
            const categorySelection = {
                books: selected[0],
                movies: selected[1],
                songs: selected[2],
                cities: selected[3],
            };
            const res = await fetch("http://localhost:5000/random", {
            method: "POST",
            headers: {"Content-Type" : "application/json"},
            body: JSON.stringify({userInput, counter, categories: categorySelection}),
        });
            const data = await res.json();
            console.log("Response data:", data);
            if (data.question) setQuestion(data.question);
            if (data.answer) setAnswer(data.answer);
            if (data.category) {
                const catIndex = ["Books", "Movies", "Songs", "Cities"].findIndex(
                    (cat) => cat === data.category
                );
                if (catIndex !== -1) {
                    setRandomItem(categories[catIndex]);
                    setRandomColor(categoryColor[catIndex]);
                }
            }

            setCounter((prev) => prev + 1);

        } catch (err) {
            setQuestion("Couldn't find a question!");
        }

        document.getElementById("guess").disabled = false;
        setUserAnswer("");
    };

    const answering = () => {
        if (userAnswer == answer && answer != ""){
            setPoints(prevPoints => prevPoints + 1);
            setUserAnswer("");
            document.getElementById("guess").disabled = true;
            setQuestionCounter(prev => prev + 1);
        }
    };
  return (
      <>
          <div id="app">
          <header id="header">
              <h1>Trivia Game!</h1>
              <h5>Made by Abby Buchholz, Sophia Pappous, and Adam Jarvis</h5>
          </header>
              <div id="mainBlock">
          <main>
              <div id="topBar">
                  <div id="category">Category:</div>
                  {randomItem && randomColor && <div id="categoryDisplay" style={{backgroundColor: randomColor}}>{randomItem}</div>}
                      <div id="points">
              <p>Points:</p>
              <p>{points}</p>
                          </div>
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
                      <button onClick={() => pickRandomItem("next")} className="buttonGuess"></button>
                      <span>Next</span>
                  </label>
              </div>
          </main>
              <aside>
                  <h3>Settings</h3>
                  <p>Sorting Algorithms:</p>
                  <div className="flexBox">
                      <label className="buttonSort">
                          <button onClick={() => pickRandomItem("mergeSort")} className="buttonGuess"></button>
                          <span>Merge Sort</span>
                      </label>
                      <label className="buttonSort">
                          <button onClick={() => pickRandomItem("quickSort")} className="buttonGuess"></button>
                          <span>Quick Sort</span>
                      </label>
                      <label className="buttonSort">
                          <button onClick={() => pickRandomItem("randomize")} className="buttonGuess"></button>
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
              </aside>
                </div>
          </div>
      </>
  )
}

export default App
