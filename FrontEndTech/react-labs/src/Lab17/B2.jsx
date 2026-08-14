import React from 'react'

function B2() {
    const faculties=["Gopi Sanghani","Arjun Bala","Vishal Kansagara","Dhavnik Zala"]
  return (
    <div>
        <h2>List of faculties</h2>
        <ul>
            {faculties.map((faculty)=> <li>{faculty}</li>)}
        </ul>
    </div>
  )
}

export default B2