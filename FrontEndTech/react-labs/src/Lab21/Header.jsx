import React from "react";
import { Link } from "react-router-dom";

function Header() {
  return (
    <div className="nav">
      <Link className="link" to="a1">
        A1
      </Link>
      <Link className="link" to="a2">
        A2
      </Link>
      <Link className="link" to="/">
        Back to home
      </Link>
    </div>
  );
}

export default Header;
