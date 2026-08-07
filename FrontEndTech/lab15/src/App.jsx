import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from './assets/vite.svg'
import heroImg from './assets/hero.png'
import './App.css'
import 'bootstrap/dist/css/bootstrap.min.css';
import Header from './Header'
import MainContent from './MainContent'
import Footer from './Footer'


function App() {

  return (
    <>
<Header/>
<MainContent/>
<Footer/>
    </>
  )
}

export default App
