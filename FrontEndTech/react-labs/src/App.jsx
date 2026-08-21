import "bootstrap/dist/css/bootstrap.min.css";
import A1_17 from "./Lab17/A1";
import B2_17 from "./Lab17/B2";
import B3_17 from "./Lab17/B3";
import C4_17 from "./Lab17/C4";
import { BrowserRouter, Route, Routes } from "react-router-dom";
import Layout from "./Layout";
import Home from "./Home";
import Layout20 from "./Lab20/Layout";
import Layout17 from "./Lab17/Layout";
import Home20 from "./Lab20/Home";
import Services20 from "./Lab20/Services";
import Contact20 from "./Lab20/Contact";
import About20 from "./Lab20/About";
import Layout21 from "./Lab21/Layout"
import "./App.css"
import A1_21 from "./Lab21/A1";
import A2_21 from "./Lab21/A2";

function App() {
  return (
    <>
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<Layout />}>
            <Route index element={<Home />} />
            <Route path="/lab17" element={<Layout17 />}>
              <Route path="a1" element={<A1_17 />} />
              <Route path="b2" element={<B2_17 />} />
              <Route path="b3" element={<B3_17 />} />
              <Route path="c4" element={<C4_17 />} />
            </Route>
            <Route path="/lab20" element={<Layout20 />}>
              <Route path="home" element={<Home20 />} />
              <Route path="services" element={<Services20 />} />
              <Route path="about" element={<About20 />} />
              <Route path="contact" element={<Contact20 />} />
            </Route>
            <Route path="/lab21" element={<Layout21 />}>
              <Route path="a1" element={<A1_21 />} />
              <Route path="a2" element={<A2_21 />} />
            </Route>
          </Route>
        </Routes>
      </BrowserRouter>
    </>
  );
}

export default App;
