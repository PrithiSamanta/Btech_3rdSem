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
import Layout18 from "./Lab18/Layout";
import Home20 from "./Lab20/Home";
import Services20 from "./Lab20/Services";
import Contact20 from "./Lab20/Contact";
import About20 from "./Lab20/About";
import Layout21 from "./Lab21/Layout";
import "./App.css";
import A1_21 from "./Lab21/A1";
import A2_21 from "./Lab21/A2";
import A_18 from "./Lab18/A/App";
import B_18 from "./Lab18/B/App";
import App19 from "./Lab19/App";
import Layout22 from "./Lab22/Layout";
import A1_22 from "./Lab22/A1";
import Layout23 from "./Lab23/Layout";
import A1_23 from "./Lab23/A1";
import Layout24 from "./Lab24/Layout";
import A1_24 from "./Lab24/A1";
import A1Add from "./Lab24/A1Add";
import A1Details from "./Lab24/A1Details";
import A1Update from "./Lab24/A1Update";

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
            <Route path="/lab18" element={<Layout18 />}>
              <Route path="a" element={<A_18 />} />
              <Route path="b" element={<B_18 />} />
            </Route>
            <Route path="/lab19" element={<App19 />}></Route>
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
            <Route path="/lab22" element={<Layout22 />}>
              <Route path="a1" element={<A1_22 />} />
            </Route>
            <Route path="/lab23" element={<Layout23 />}>
              <Route path="a1" element={<A1_23 />} />
            </Route>
            <Route path="/lab24" element={<Layout24 />}>
              <Route path="a1" element={<A1_24 />} />
              <Route path="add" element={<A1Add />} />
              <Route path="details/:id" element={<A1Details />} />
              <Route path="update/:id" element={<A1Update />} />
            </Route>
          </Route>
        </Routes>
      </BrowserRouter>
    </>
  );
}

export default App;
