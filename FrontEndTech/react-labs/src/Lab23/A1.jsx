import React, { useState } from "react";

function A1() {
  const [products, setProducts] = useState([]);
  const [name, setName] = useState("");
  const [price, setPrice] = useState("");
  const [editIndex, setEditIndex] = useState(-1);

  function saveData() {
    if (name == "" || price == "") {
      alert("Please enter data:");
      return;
    }
    let temp = [...products];

    if (editIndex == -1) temp.push({ name: name, price: price });
    else {
      temp[editIndex].name = name;
      temp[editIndex].price = price;
    }
    setProducts(temp);

    setEditIndex(-1);
    setName("");
    setPrice("");
  }

  function editData(i) {
    setEditIndex(i);
    setName(products[i].name);
    setPrice(products[i].price);
  }

  function deleteData(i) {
    let temp = [...products];
    temp.splice(i, 1);
    setProducts(temp);
  }

  return (
    <div className="container">
      <h1>CRUD Operation on Products Array</h1>

      <input
        type="text"
        value={name}
        onChange={(e) => setName(e.target.value)}
        placeholder="Product Name"
      />
      <input
        type="text"
        value={price}
        onChange={(e) => setPrice(e.target.value)}
        placeholder="Product Price"
      />
      <button onClick={saveData}>{editIndex === -1 ? "Add" : "Edit"}</button>

      <table className="table table-hover">
        <thead>
          <tr>
            <th>ID</th>
            <th>Product Name</th>
            <th>Price</th>
            <th>Action</th>
          </tr>
        </thead>
        <tbody>
          {products.map((pro, i) => (
            <tr>
              <td>{i + 1}</td>
              <td>{pro.name}</td>
              <td>{pro.price}</td>

              <td>
                <button onClick={() => editData(i)}>Edit</button>
                <button onClick={() => deleteData(i)}>Delete</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default A1;
