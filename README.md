How to run this code:

You will need to have access to some kind of terminal/powershell. I (Abby) personally used CLion's during development
because we need to run two simultaneously: one for the frontend react.js and one for the local server that facilliates
frontend-backend interaction.

Frontend:
In the terminal you need to type the following:

cd {YOUR\DIRECTORY}\DSAProject2TriviaGame\my-app\src
npm run dev

This will run a localhost, usually 5173. Access this to see the frontend.

Backend:
In a separate terminal tab you need to type the following:

cd {YOUR\DIRECTORY}\DSAProject2TriviaGame\src
node server.js

This will run a localhost as well, that being localhost:5000.

This will allow interaction between our C++ code and the frontend and allow it save data.