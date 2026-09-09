import React, { useState } from "react";
import B from "./B";

function A({ name, setName }) {
  const [input, setInput] = useState("");
  return (
    <>
      <input type="text" onChange={(e) => setInput(e.target.value)} />
      <B name={name} setName={setName} input={input} />
    </>
  );
}

export default A;
