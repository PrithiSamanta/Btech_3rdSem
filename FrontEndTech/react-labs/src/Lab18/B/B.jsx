import React, { useState } from "react";
import C from "./C";

function B({ name, setName, input }) {
  return (
    <>
      <button onClick={() => setName(input)}>Click</button>
      <C name={name} />
    </>
  );
}

export default B;
