import React, { useEffect, useState } from "react";

function A2() {
  const [count, setCount] = useState(0);
  const [name, setName] = useState("abc");

  useEffect(() => {
    console.log("No dependences effect.");
  });

  useEffect(() => {
    console.log("Empty array effect.");
  }, []);

  useEffect(() => {
    console.log("Count array effect.");
  }, [count]);

  return (
    <div className="mx-3">
      <h3>Demonstration of useEffect Hook.</h3>
      <h5>{count}</h5>
      <button
        className="btn btn-primary me-2"
        onClick={() => {
          setCount(count + 1);
        }}
      >
        Increment
      </button>

      <h5>{name}</h5>
      <button
        className="btn btn-primary me-2"
        onClick={() => {
          setName("xyz");
        }}
      >
        Change
      </button>
    </div>
  );
}

export default A2;
