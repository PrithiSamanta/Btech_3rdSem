import React from 'react'

function A3() {
    const isDisplay = false
    return (

        <div>
            {isDisplay ? <div>Show display</div> : <div>Hidden Display</div>}
        </div>
    )
}

export default A3