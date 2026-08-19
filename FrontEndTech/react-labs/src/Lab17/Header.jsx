import React from "react";
import { Link } from "react-router-dom";

function Header() {
  return (
    <div className="nav">
      <Link className="link" to="a1">
        A1
      </Link>
      <Link className="link" to="b2">
        B2
      </Link>
      <Link className="link" to="b3">
        B3
      </Link>
      <Link className="link" to="c4">
        C4
      </Link>
      <Link className="link" to="/">
        Back to home
      </Link>
    </div>
  );
}

export default Header;
