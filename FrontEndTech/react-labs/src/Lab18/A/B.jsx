import React, { useState } from "react";
import C from "./C";

function B({ name, setName }) {
  const [input, setInput] = useState("");
  return (
    <>
      <input type="text" onChange={(e) => setInput(e.target.value)} />
      <button onClick={() => setName(input)}>Click</button>
      <C name={name} />
    </>
  );
}

export default B;
