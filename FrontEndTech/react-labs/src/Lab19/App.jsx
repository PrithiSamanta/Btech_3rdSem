import React, { useState } from "react";
import Login from "./Login";
import Home from "./Home";

function App() {
  const [currentUser, setCurrentUser] = useState("");
  return (
    <>
      {currentUser === "" ? (
        <Login setCurrentUser={setCurrentUser} />
      ) : (
        <Home user={currentUser} />
      )}
    </>
  );
}

export default App;
