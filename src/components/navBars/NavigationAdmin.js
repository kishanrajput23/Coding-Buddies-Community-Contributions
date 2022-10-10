import React, { Component } from 'react'
import { Navbar, Nav,} from 'react-bootstrap'
import logo from '../../images/logo.png'
import '../../cssComponents/navigation.css'; 

export class NavigationAdmin extends Component {    

    render() {
        return (
            <div>
                <Navbar className="sticky-nav" collapseOnSelect expand='xl' variant='dark' /*fixed="top"*/ bg='dark'>
                        <Navbar.Toggle aria-controls='responsive-navbar-nav' />
                        <Navbar.Collapse id='responsive-navbar-nav'>
                            <img className="img-responsive" src={logo}  alt='cg logo'/>
                            <h2 className="heading">Health Reminder </h2>
                            <Nav className="ml-auto">
                                <Nav.Link href='/admin'>Home</Nav.Link>
                                <Nav.Link href='/MentalList'>Health Tips</Nav.Link>
                                <Nav.Link href='/DiseaseList'>Disease</Nav.Link>
                                <Nav.Link href='/DietList'>Diet</Nav.Link>
                                <Nav.Link href="/doctorList">Doctors</Nav.Link>
                                <Nav.Link href="/patientList">Patients</Nav.Link>
                                {/* <Link to='footer' className="contact">Contact Us</Link> */}
                                <Nav.Link href="/">Logout</Nav.Link>
                            </Nav>
                        </Navbar.Collapse>
                </Navbar>
            </div>
            )
        }
    }
        
export default NavigationAdmin;
        