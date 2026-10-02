import React, { useEffect, useState } from "react";
import { Link, useParams } from "react-router-dom";

function A1Details() {
  const { id } = useParams();

  const [faculty, setFaculty] = useState({});

  useEffect(() => {
    fetch(import.meta.env.VITE_MOCK + "faculty/" + id, { method: "GET" })
      .then((res) => res.json())
      .then((res) => {
        setFaculty(res);
        console.log(res);
      });
  }, []);

  return (
    <div>
      <div className="row justify-content-center align-items-center">
        <div class="col-3 p-0" key={faculty.id}>
          <img
            src={faculty.image}
            className="card-img-top image-fluid"
            alt="..."
          />
          <div className="card-body mt-2">
            <h5 className="card-title">{faculty.name}</h5>
            <p className="card-text">Experience : {faculty.exp}</p>
            <Link className="btn btn-info me-2" to={"/lab24/update/" + faculty.id}>
              Update
            </Link>
            <Link className="btn btn-primary" to={"/lab24/a1"}>
              Go Back
            </Link>
          </div>
        </div>
      </div>
    </div>
  );
}

export default A1Details;
