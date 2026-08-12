import React from 'react'

function A2() {
    let bg = 'black';
    function changeBg() {

        if (bg === 'black') {
            document.body.style.backgroundColor = "pink"
            bg = 'pink'
        }
        else {
            document.body.style.backgroundColor = "black"
            bg = 'black'
        }
    }
    return (
        <div>
            <p>Click the button below to change bg.</p>
            <button onClick={changeBg}>Click</button>
        </div>
    )
}

export default A2