import { useState } from 'react'
import './App.css'

function App() {
  const [algoOneToggle] = useState(0)
    const [algoTwoToggle] = useState(0)
    const [points] = useState(0)

  return (
      <>
          <body>
          <header>
              <h1>Trivia Game!</h1>
          </header>

          <content>
          <main>
              <div>
              <p>Category:</p>
              <div>Books</div>
              <p>Points:</p>
              <p>3</p>
              </div>
              <div id="question">
                  <p>Hello!</p>
              </div>
          </main>
              <aside>
                  <p>Settings</p>
                  <label className="switch">
                      <input type="checkbox"/>
                      <span className="slider round"></span>
                  </label>
                  <p>Merge Sort</p>
                  <label className="switch">
                      <input type="checkbox"/>
                      <span className="slider round"></span>
                  </label>
                  <p>Heap Sort</p>
                  <p>Select categories:</p>
                  <div>Books, Movies, Songs, Cities</div>
                  <p>Special Categorization:</p>

                  <select name="verb" id="verb">
                      <option value="Before">Before</option>
                      <option value="After">After</option>
                      <option value="Only">Only</option>
                  </select>
                  <input type="number" id="quantity" name="quantity" min="0" max="2025"></input>
              </aside>
          </content>
          </body>
      </>
  )
}

export default App
