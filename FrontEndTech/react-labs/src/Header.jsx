import React from "react";
import { Link } from "react-router-dom";

function Header() {
  return (
    <div className="nav">
      <Link className="link fs-5" to="/lab17">
        Lab17
      </Link>
      <Link className="link fs-5" to="/lab20">
        Lab20
      </Link>
      <Link className="link fs-5" to="/lab21">
        Lab21
      </Link>
    </div>
  );
}

export default Header;
