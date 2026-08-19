import React from "react";
import { Link } from "react-router-dom";

function Header() {
  return (
    <div className="nav">
      <Link className="link" to="home">
        Home
      </Link>
      <Link className="link" to="about">
        About
      </Link>
      <Link className="link" to="contact">
        Contact
      </Link>
      <Link className="link" to="services">
        Services
      </Link>
      <Link className="link" to="/">
        Back to home
      </Link>
    </div>
  );
}

export default Header;
