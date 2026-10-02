import React, { useState } from "react";
import { useNavigate } from "react-router-dom";

function A1Add() {
  const [faculty, setFaculty] = useState([]);

  const navigate = useNavigate();

  const add = (e) => {
    e.preventDefault();

    fetch(import.meta.env.VITE_MOCK + "faculty", {
      method: "POST",
      body: JSON.stringify(faculty),
      headers: {
        "Content-Type": "application/json",
      },
    })
      .then((res) => res.json())
      .then((res) => {
        setFaculty(res);
        console.log(res);
        navigate("/lab24/a1");
      });
  };
  return (
    <>
      <div className="container">
        <form onSubmit={add}>
          <div class="mb-3">
            <label for="name" class="form-label">
              Faculty Name
            </label>
            <input
              type="text"
              id="name"
              class="form-control"
              required
              onChange={(e) => {
                setFaculty({ ...faculty, name: e.target.value });
              }}
            />
          </div>
          <div class="mb-3">
            <label for="image" class="form-label">
              Faculty Image
            </label>
            <input
              type="text"
              id="image"
              class="form-control"
              onChange={(e) => {
                setFaculty({ ...faculty, image: e.target.value });
              }}
            />
          </div>
          <div class="mb-3">
            <label for="exp" class="form-label">
              Faculty Experience
            </label>
            <input
              type="text"
              id="exp"
              class="form-control"
              required
              onChange={(e) => {
                setFaculty({ ...faculty, exp: e.target.value });
              }}
            />
          </div>
          <button type="submit" class="btn btn-primary">
            Add
          </button>
        </form>
      </div>
    </>
  );
}

export default A1Add;
