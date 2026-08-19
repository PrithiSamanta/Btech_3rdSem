import React from "react";

function A1() {
  const fruits = ["Mango", "Banana", "Apple", "Kiwi"];
  return (
    <ul>
      {fruits.map((fruit) => (
        <li>{fruit}</li>
      ))}
    </ul>
  );
}

export default A1 ;
