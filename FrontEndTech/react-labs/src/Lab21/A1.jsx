import React, { useState } from "react";

function A1() {
  const [count, setCount] = useState(0);
  return (
    <div className="mx-3">
      <h3>Demonstration of useState Hook.</h3>
      <h5>{count}</h5>
      <button
        className="btn btn-primary me-2"
        onClick={() => {
          setCount(count + 1);
        }}
      >
        Increment
      </button>
      <button
        className="btn btn-primary me-2"
        onClick={() => {
          setCount(count - 1);
        }}
      >
        Decrement
      </button>
      <button
        className="btn btn-primary me-2"
        onClick={() => {
          setCount(0);
        }}
      >
        Reset
      </button>
    </div>
  );
}

export default A1;
