import React, { useState } from "react";

function Login({ setCurrentUser }) {
  const [user, setUser] = useState("");
  const [password, setPassword] = useState("");
  return (
    <>
      <label htmlFor="username">UserName : </label>
      <input
        type="text"
        id="username"
        onChange={(e) => setUser(e.target.value)}
      />
      <br />
      <label htmlFor="password">Password : </label>
      <input
        type="password"
        id="password"
        onChange={(e) => setPassword(e.target.value)}
      />
      <br />
      <button
        onClick={() => {
          if (user === "admin" && password === "1234") setCurrentUser(user);
          else alert("Invalid login");
        }}
      >
        Login
      </button>
    </>
  );
}

export default Login;
