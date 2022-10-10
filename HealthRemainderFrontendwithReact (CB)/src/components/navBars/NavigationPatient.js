import React, { Component } from 'react'
import { Navbar, Nav,} from 'react-bootstrap'
import logo from '../../images/logo.png'
import '../../cssComponents/navigation.css'; 


export class Navigation extends Component {
    
    onConfirm() {
        // Preform your action.
    }

    render() {
        return (
            <div>
                <Navbar className="sticky-nav" collapseOnSelect expand='xl' variant='dark' /*fixed="top"*/ bg='dark'>
                        <Navbar.Toggle aria-controls='responsive-navbar-nav' />
                        <Navbar.Collapse id='responsive-navbar-nav'>
                            <img className="img-responsive" src={logo}  alt='cg logo'/>
                            <h2 className="heading" >Health Reminder</h2>
                            <Nav className="ml-auto">
                                <Nav.Link href='/patient'>Home</Nav.Link>
                                <Nav.Link href='/viewAllSlots'>Book Appointment</Nav.Link>
                                {/* <Nav.Link href='/diet'>Find Diet</Nav.Link> */}
                                <Nav.Link href='/setreminder'>Set Reminder</Nav.Link>
                                <Nav.Link href='searchpage'>Disease Search</Nav.Link>
                                <Nav.Link href="/">Logout</Nav.Link>
                            </Nav>
                        </Navbar.Collapse>
                </Navbar>
            </div>
    )
    }
}

export default Navigation;
