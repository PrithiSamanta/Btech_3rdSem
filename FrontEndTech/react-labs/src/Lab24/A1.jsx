import React, { useEffect, useState } from "react";
import { Link } from "react-router-dom";

function A1() {
  const [faculty, setFaculty] = useState([]);
  const [update, setUpdate] = useState(false);

  useEffect(() => {
    fetch(import.meta.env.VITE_MOCK + "faculty", { method: "GET" })
      .then((res) => res.json())
      .then((res) => {
        setFaculty(res);
        console.log(res);
      });
  }, [update]);

  function deleteFaculty(id) {
    fetch(import.meta.env.VITE_MOCK + "faculty" + id, {
      method: "DELETE",
    })
      .then((res) => res.json())
      .then();
  }

  return (
    <>
      <div className="container">
        <Link to="/lab24/add" className="btn btn-primary">
          Add new
        </Link>
        <div className="row g-2">
          {faculty.map((fac) => (
            <div class="card col-3 p-0" key={fac.id}>
              <img
                src={fac.image}
                className="card-img-top image-fluid"
                alt="..."
              />
              <div className="card-body">
                <h5 className="card-title">{fac.name}</h5>
                <Link
                  className="btn btn-primary"
                  to={"/lab24/details/" + fac.id}
                >
                  View Details
                </Link>
                <button
                  className="btn btn-danger"
                  onClick={() => {
                    fetch(import.meta.env.VITE_MOCK + "faculty/" + fac.id, {
                      method: "DELETE",
                    })
                      .then((res) => res.json())
                      .then((res) => setUpdate(!update));
                  }}
                >
                  Delete
                </button>
              </div>
            </div>
          ))}
        </div>
      </div>
    </>
  );
}

export default A1;
