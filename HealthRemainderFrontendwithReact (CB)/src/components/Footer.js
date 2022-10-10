import React, { Component } from "react";
import "../cssComponents/style.css";
import logo from "../images/logo.png";
import fb from "../icons/Facebook.png";
import insta from "../icons/Instagram.png";
import link from "../icons/Linkedin.png";
import twi from "../icons/Twitter.png";

export class Footer extends Component {
  render() {
    return (
      <div id="footer">
        <footer className="footer">
          <div className="footer-left col-md-4 col-sm-6">
            <p className="about">
              <span>
                <h2> About </h2>{" "}
              </span>{" "}
              Capgemini SE is a French multinational corporation that provides
              consulting, technology, professional, and outsourcing services. It
              is headquartered in Paris, France. Capgemini has over 270,000
              employees in over 50 countries, of whom nearly 120,000 are in
              India.
              <hr></hr>
            </p>
            <div className="social-icons">
              <li>
                <a href="https://www.facebook.com/CapgeminiIndia/">
                  <img className="logo" src={fb} alt="fb" />
                  <i className="fa fa-facebook"></i>
                </a>
              </li>
              <li>
                <a href="https://twitter.com/Capgemini?ref_src=twsrc%5Egoogle%7Ctwcamp%5Eserp%7Ctwgr%5Eauthor">
                  <img className="logo" src={twi} alt="twi" />
                  <i className="fa fa-twitter"></i>
                </a>
              </li>
              <li>
                <a href="https://www.linkedin.com/company/capgemini/mycompany/verification/">
                  <img className="logo" src={link} alt="logo" />
                  <i className="fa fa-linkedin"></i>
                </a>
              </li>
              <li>
                <a href="https://www.instagram.com/capgeminiindia/?hl=en">
                  <img className="logo" src={insta} alt="insta" />
                  <i className="fa fa-instagram"></i>
                </a>
              </li>
            </div>
          </div>
          <div className="footer-center col-md-4 col-sm-6">
            <div>
              <i className="fa fa-map-marker"></i>
              <p>
                <span> 123 Street, Tech Road</span> Pune, India
              </p>
            </div>
            <div>
              <i className="fa fa-phone"></i>
              <p> (+91) 9999 123 456</p>
            </div>
            <div>
              <i className="fa fa-envelope"></i>
              <p>
                <a href="/#"> healthreminder@capgemini.com</a>
              </p>
            </div>
          </div>
          <div className="footer-right col-md-4 col-sm-6">
            <img className="logo" src={logo} alt="logo" />
            <hr></hr>
            <p className="menu">
              <a href="/"> Home</a> |<a href="/Doctor"> Doctor</a> |
              <a href="/Admin"> Admin</a> |<a href="/Patient"> Patient</a> |
              <a href="/#"> Contact</a>
            </p>
            <p className="name"> Capgemini &copy; 2021</p>
          </div>
        </footer>
      </div>
    );
  }
}

export default Footer;
