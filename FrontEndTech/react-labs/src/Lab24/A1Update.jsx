import React, { useEffect, useState } from "react";
import { useNavigate, useParams } from "react-router-dom";

function A1Update() {
  const [faculty, setFaculty] = useState({});

  const navigate = useNavigate();
  const { id } = useParams();

  const update = (e) => {
    e.preventDefault();

    fetch(import.meta.env.VITE_MOCK + "faculty/" + id, {
      method: "PUT",
      body: JSON.stringify(faculty),
      headers: {
        "Content-Type": "application/json",
      },
    })
      .then((res) => res.json())
      .then((res) => {
        setFaculty(res);
        navigate("/lab24/a1");
      });
  };

  const [data, setData] = useState({});

  useEffect(() => {
    fetch(import.meta.env.VITE_MOCK + "faculty/" + id, { method: "GET" })
      .then((res) => res.json())
      .then((res) => {
        setData(res);
        setFaculty(res);
      });
  }, []);
  return (
    <>
      <div className="container">
        <form onSubmit={update}>
          <div class="mb-3">
            <label for="name" class="form-label">
              Faculty Name
            </label>
            <input
              type="text"
              id="name"
              class="form-control"
              required
              defaultValue={data.name}
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
              defaultValue={data.image}
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
              defaultValue={data.exp}
              onChange={(e) => {
                setFaculty({ ...faculty, exp: e.target.value });
              }}
            />
          </div>
          <button type="submit" class="btn btn-primary">
            Update
          </button>
        </form>
      </div>
    </>
  );
}

export default A1Update;
