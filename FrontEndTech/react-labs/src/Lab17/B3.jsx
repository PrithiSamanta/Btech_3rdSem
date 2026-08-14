import React from 'react'

function B3() {
    const students = [{ id: 1, name: "Prithi", course: "CSE" }, { id: 1, name: "Prithi", course: "CSE" }, { id: 1, name: "Prithi", course: "CSE" }, { id: 1, name: "Prithi", course: "CSE" }]
    return (
        <table border={1}>
            <thead>
                <tr>
                    <th>Std ID</th>
                    <th>Std Name</th>
                    <th>Course</th>
                </tr>
            </thead>
            <tbody>
                {students.map((student)=>
                <tr>
                    <td>{student.id}</td>
                    <td>{student.name}</td>
                    <td>{student.course}</td>
                </tr>
                )}
            </tbody>
        </table>
    )
}

export {B3};