import React from "react";

function C4() {
  const products = [
    {
      id: 1,
      name: "Wireless Noise-Canceling Headphones",
      category: "Electronics",
      price: 129.99,
      rating: 4.7,
      inStock: true,
      tags: ["audio", "gadgets", "wireless"],
    },
    {
      id: 2,
      name: "Ergonomic Office Chair",
      category: "Furniture",
      price: 249.5,
      rating: 4.5,
      inStock: true,
      tags: ["office", "home", "comfort"],
    },
    {
      id: 3,
      name: "Stainless Steel Water Bottle",
      category: "Fitness & Outdoor",
      price: 24.99,
      rating: 4.2,
      inStock: false,
      tags: ["eco-friendly", "hydration", "sports"],
    },
    {
      id: 4,
      name: "Mechanical Gaming Keyboard",
      category: "Electronics",
      price: 89.99,
      rating: 4.8,
      inStock: true,
      tags: ["gaming", "peripherals", "rgb"],
    },
    {
      id: 5,
      name: "Organic Green Tea Blend",
      category: "Grocery",
      price: 12.95,
      rating: 4.6,
      inStock: true,
      tags: ["beverages", "organic", "health"],
    },
  ];

  return (
    <div className="d-flex gap-5">
      {products.map((p) => (
        <div class="card" style={{ width: 18 + "rem" }}>
          <img src="..." class="card-img-top" alt="..." />
          <div class="card-body">
            <h5 class="card-title">{p.name}</h5>
            <p class="card-text">Category : {p.category}</p>
            <p class="card-text">Rating : {p.rating}/5</p>
            {p.inStock ? (
              <p class="card-text text-success fw-bold">Available</p>
            ) : (
              <p className="text-danger fw-bold">Out of stock</p>
            )}
            <p class="card-text fw-bold">Price{p.price}</p>
            {p.inStock ? (
              <a href="#" class="btn btn-primary">
                Buy Now
              </a>
            ) : (
              <a href="#" class="btn btn-primary disabled">
                Buy Now
              </a>
            )}
          </div>
        </div>
      ))}
    </div>
  );
}

export default C4;
