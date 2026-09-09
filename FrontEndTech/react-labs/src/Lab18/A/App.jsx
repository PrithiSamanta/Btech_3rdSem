import React, { useState } from "react";
import A from "./A";

function App() {
  const [name, setName] = useState("");
  return <A name={name} setName={setName} />;
}

export default App;
