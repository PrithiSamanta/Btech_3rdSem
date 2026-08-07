import React from 'react'

function MainContent() {
  return (
    <div className='container-fuild'>
        <div className='row'>
            <div className='col-4 border border-1 p-5'>Side bar</div>
    <div style={{height:200}} className='text-center pt-5 col-8 border border-1'>This is main content</div>
    </div>
    </div>
  )
}

export default MainContent