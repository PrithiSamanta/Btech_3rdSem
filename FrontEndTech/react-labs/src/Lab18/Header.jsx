import React from "react";
import { Link } from "react-router-dom";

function Header() {
  return (
    <div className="nav">
      <Link className="link" to="a">
        18-A
      </Link>
      <Link className="link" to="b">
        18-B
      </Link>
    </div>
  );
}

export default Header;
