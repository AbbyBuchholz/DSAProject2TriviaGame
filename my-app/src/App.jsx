import { useState, useEffect, useRef } from 'react'
import './App.css'

function App() {
    const options = ["Op1", "Op2", "Op3", "Op4"];
    const categories = ["Books", "Movies", "Songs", "Cities"];
    const categoryColor = ['#C28686', '#C5B885', '#C78FB4', '#8CC084'];

  const [selected, setSelected] = useState(Array(options.length).fill(true));
  const [randomItem, setRandomItem] = useState("Click Next!");
    const [randomColor, setRandomColor] = useState('white');


    const inputRef = useRef();

    const [customTime, setCustomTime] = useState("");
    const [timeLeft, setTimeLeft] = useState("");
    const [isActive, setActivity] = useState(false);
    const [progressDone, setProgressDone] = useState(false);
    const [progress, setProgress] = useState(100);

    // const handleChange = (e) => {
    //     setCustomTime(e.target.value);
    // };


    var customTimeMilliseconds = customTime * 60 * 1000;

    var customTimeSeconds = customTime * 60;

    var seconds = customTimeSeconds - (customTime * 60);

    useEffect(() =>{
        let timer;

        if (isActive && timeLeft > 0){
            timer = setTimeout(() =>{
                setTimeLeft((prevTime) => prevTime -1);
            }, 1000);
        } else if(timeLeft == 0){
            setActivity(false);
            setProgressDone(true);
        }
        return () => clearTimeout(timer);
    }, [timeLeft, isActive]);
    var minutes = Math.floor(timeLeft / 60);
    var seconds = timeLeft - minutes * 60;

    if(seconds < 10){
        seconds = "0"+seconds;
    }
    // const handleInputChange = (event) => {
    //     setCustomTime(inputRef.current.value);
    // }


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

    const pickRandomItem = () => {
        let randomIndex = Math.floor(Math.random() * categories.length);
        //console.log(randomIndex, selected[randomIndex]);
        while (selected[randomIndex] !== true){
            randomIndex = Math.floor(Math.random() * categories.length);
        }
        setRandomItem(categories[randomIndex]);
        setRandomColor(categoryColor[randomIndex]);

        /*setTimeLeft(res);
        setActivity(true);
        setProgressDone(false);
        console.log(isActive, progressDone, timeLeft);*/
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
              <p>3</p>
                  </span>
              </div>
              <div id="timeBar"></div>
              <div id="question">
                  <p>Hello!</p>
              </div>
              <div id="guessingArea">
                  <p>Guess:</p>
                  <input type="text" placeholder="Type here..."/>
                  <label className="buttonBar">
                      <button className="buttonGuess"></button>
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
                  <div>
                      <span>Guessing Time:</span>
                      <span>
                      <select>
                          <option value="30">0:30</option>
                          <option value="45">0:45</option>
                          <option value="60" selected>1:00</option>
                          <option value="90">1:30</option>
                          <option value="120">2:00</option>
                      </select></span>
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
