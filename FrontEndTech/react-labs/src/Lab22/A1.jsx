import React, { useState } from "react";

function A1() {
  const [display, setDisplay] = useState("");
  //   const [isError, setIsError] = useState(false); //tried to implement error erased when error occurs after click
  function buttonClick(val) {
    // if (isError===true) setDisplay("");
    if (val === "C") setDisplay("");
    else if (val === "=") {
      try {
        setDisplay(eval(display));
      } catch (err) {
        // setIsError(true);
        setDisplay(err);
      }
    } else setDisplay(display + val);
  }
  return (
    <div
      className="calculator overflow-hidden container-fluid p-4 w-25"
      style={{ minWidth: 250 + "px" }}
    >
      <div className="row mb-3">
        <div className="col-12 px-1">
          <input
            className="form-control text-end"
            type="text"
            value={display}
            readOnly
          />
        </div>
      </div>

      <div className="buttons row gx-4 ">
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("7")}
        >
          7
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("8")}
        >
          8
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("9")}
        >
          9
        </button>
        <button className="col btn-danger btn" onClick={() => buttonClick("C")}>
          C
        </button>
      </div>
      <div className="buttons row gx-4 ">
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("4")}
        >
          4
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("5")}
        >
          5
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("6")}
        >
          6
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("/")}
        >
          /
        </button>
      </div>
      <div className="buttons row gx-4 ">
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("1")}
        >
          1
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("2")}
        >
          2
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("3")}
        >
          3
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("*")}
        >
          *
        </button>
      </div>
      <div className="buttons row gx-4 ">
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("0")}
        >
          0
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("+")}
        >
          +
        </button>
        <button
          className="col btn btn-secondary"
          onClick={() => buttonClick("-")}
        >
          -
        </button>
        <button
          className="col btn btn-success"
          onClick={() => buttonClick("=")}
        >
          =
        </button>
      </div>
    </div>
  );
}

export default A1;
