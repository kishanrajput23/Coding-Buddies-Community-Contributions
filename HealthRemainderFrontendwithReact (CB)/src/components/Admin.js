import React, { Component } from 'react'
import NavigationAdmin from './navBars/NavigationAdmin';
import i2 from '../images/diseaseslong.webp';
// import i2 from '../images/updatedisease.jpg';
import i1 from '../images/mentalhealth.jpg';
import i3 from '../images/updatediet.jpg';
import i4 from '../images/doc_img.jpg';
import i5 from '../images/patient12.jpg';
import { Card } from "react-bootstrap";


export class Admin extends Component {
    render() {
        return (
            <div>
                <NavigationAdmin />               
              <div className="container"> 
                <p> </p>
                <h2>  Welcome Admin! </h2>
                <p> </p>
                <div className="row">
                     <div className="col-sm">
                        <Card>
                            <Card.Img variant="top" src={i1} style={{ height: "20rem" }} />
                            <Card.Body>
                                <Card.Title>
                                    <h5>Edit Health Tips</h5>
                                </Card.Title>
                                <Card.Text>
                                    <p>
                                        Click here to update the Mental Health Tips shown to the Patient Module
                                    </p>
                                </Card.Text>
                                </Card.Body>
                                <Card.Footer>
                                <Card.Link href="/MentalList" className="btn btn-primary">
                                    Edit Health Tips
                                </Card.Link>               
                            </Card.Footer>  
                        </Card>
                    </div>
                    <div className="col-sm">
                        <Card>
                            <Card.Img variant="top" src={i2} style={{ height: "20rem" }} />
                            <Card.Body>
                                <Card.Title>
                                    <h5>Edit Diseases</h5>
                                </Card.Title>
                                <Card.Text>
                                    <p>
                                        Click here to update the List of Diseases shown to the Patient Module
                                    </p>
                                </Card.Text>
                                </Card.Body>
                                <Card.Footer>
                                <Card.Link href="/DiseaseList" className="btn btn-primary">
                                    Edit Disease
                                </Card.Link>             
                            </Card.Footer>  
                        </Card>
                    </div>
                    <div className="col-sm">
                        <Card>
                            <Card.Img variant="top" src={i3} style={{ height: "20rem" }} />
                            <Card.Body>
                                <Card.Title>
                                    <h5>Edit Diet</h5>
                                </Card.Title>
                                <Card.Text>
                                    <p>
                                        Click here to update Diet Information shown to the Patient Module
                                    </p>
                                </Card.Text>
                                </Card.Body>
                                <Card.Footer>
                                <Card.Link href="/DietList" className="btn btn-primary">
                                    Edit Diets
                                </Card.Link>             
                            </Card.Footer>  
                        </Card>
                    </div>
                    </div>
                    <br></br> <br></br><br></br>
                    <div className="row">
                    <div className="col-sm">
                        <Card>
                            <Card.Img variant="top" src={i4} style={{ height: "20rem" }} />
                            <Card.Body>
                                <Card.Title>
                                    <h5>Display All Doctors</h5>
                                </Card.Title>
                                <Card.Text>
                                    <p>
                                        Click here to Display All the Doctors and their details.
                                    </p>
                                </Card.Text>
                                </Card.Body>
                                <Card.Footer>
                                <Card.Link href="/DoctorList" className="btn btn-primary">
                                    Show Doctors
                                </Card.Link>             
                            </Card.Footer>  
                        </Card>
                    </div>
                    <div className="col-sm">
                        <Card>
                            <Card.Img variant="top" src={i5} style={{ height: "20rem" }} />
                            <Card.Body>
                                <Card.Title>
                                    <h5>Display All Patients</h5>
                                </Card.Title>
                                <Card.Text>
                                    <p>
                                        Click here to Display All the Patients and their details.
                                    </p>
                                </Card.Text>
                                </Card.Body>
                                <Card.Footer>
                                <Card.Link href="/PatientList" className="btn btn-primary">
                                    Show Patients
                                </Card.Link>             
                            </Card.Footer>  
                        </Card>
                    </div>
                    </div>
                </div>
            </div>
        )
    }
}

export default Admin
