import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/button';
import AllDoctorDetailsServices from '../../services/AllDoctorDetailsServices';
import DoctorNavigation from '../navBars/DoctorNavigation'

class DoctorProfileCreate extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
            doctorId:0,
            verfStatus:true,
            doctorSpec:"",
            doctorCertFile:"Certified",
            doctorName:"",
            errors: {}
        }
        // this.changeIdHandler = this.changeIdHandler.bind(this);
        this.changeDoctorNameHandler = this.changeDoctorNameHandler.bind(this);
        this.changeDoctorSpecHandler = this.changeDoctorSpecHandler.bind(this);
        this.addDoctor = this.addDoctor.bind(this);
    }

    handleValidation(){
        let doctorSpec = this.state.doctorSpec;
        let doctorName = this.state.doctorName;
        let errors = {};
        let formIsValid = true;


        //doctorName
        if(!doctorName){
            formIsValid = false;
            errors["doctorName"] = "Cannot be empty";
         }
   
         if(typeof doctorName !== "undefined"){
             if(doctorName.length<1 || doctorName.length>100){
               formIsValid = false;
               errors["doctorName"] = "Should be between 1 and 100 characters";
             }       
             if(!doctorName.match(/^[a-zA-Z ]*$/)){
                 formIsValid = false;
                 errors["doctorName"] = "Please enter only Alphabets";
              }    
         }

         //doctorSpec
        if(!doctorSpec){
            formIsValid = false;
            errors["doctorSpec"] = "Cannot be empty";
         }
   
         if(typeof doctorSpec !== "undefined"){
             if(doctorSpec.length<1 || doctorSpec.length>100){
               formIsValid = false;
               errors["doctorSpec"] = "Should be between 1 and 100 characters";
             }       
             if(!doctorSpec.match(/^[a-zA-Z ]*$/)){
                 formIsValid = false;
                 errors["doctorSpec"] = "Please enter only Alphabets";
              }    
         }

       this.setState({errors: errors});
       return formIsValid;
   }
    
    
      changeDoctorNameHandler= (event) => {
        this.setState({doctorName: event.target.value});
        console.log(this.state.doctorName)
      }
      
      changeDoctorSpecHandler= (event) => {
        this.setState({doctorSpec: event.target.value});
        console.log(this.state.doctorSpec)
      }
    
      addDoctor = () => {
        let p={doctorId: this.state.doctorId, verfStatus: this.state.verfStatus, doctorName: this.state.doctorName, doctorSpec: this.state.doctorSpec ,doctorCertFile: this.state.doctorCertFile};
        console.log('p =>' + JSON.stringify(p));
        if(this.handleValidation()){
            AllDoctorDetailsServices.createDoctor(p).then( res => {
                console.log(res);
                alert('Doctor Id: '+res.data.doctorId)
                window.location='http://localhost:3000/doctor'
            });
         }
      }
    render() {
        return (
            <div>
            <div>
                <DoctorNavigation/>
            </div>
            <form className="container mt-4" style={{textAlign:'left'}}>
                <h3>Setup your profile</h3>
                <Form.Group >
                  <Form.Label>Doctor Specialization</Form.Label>
                  <Form.Control type="text" onChange={this.changeDoctorSpecHandler} value={this.state.doctorSpec} placeholder="Enter your Specialization"/>
                  <span style={{color: "red"}}>{this.state.errors["doctorSpec"]}</span>           
              </Form.Group>
              {/* <Form.Group >
                  <Form.Label>Verification Status</Form.Label>
                  <Form.Control type="text"  value={this.state.verfStatus} />           
                  <span style={{color: "red"}}>{this.state.errors["verfStatus"]}</span>  
              </Form.Group> */}
              <Form.Group >
                  <Form.Label>Doctor Name</Form.Label>
                  <Form.Control type="text" onChange={this.changeDoctorNameHandler} value={this.state.doctorName} placeholder="Enter your Name"/>           
                  <span style={{color: "red"}}>{this.state.errors["doctorName"]}</span>  
              </Form.Group>
              {/* <Form.Group >
                  <Form.Label>Doctor Certification</Form.Label>
                  <Form.Control type="text" value={"Certified"}/>           
                  <span style={{color: "red"}}>{this.state.errors["doctorCertFile"]}</span>  
              </Form.Group> */}
              
              

              <Button variant="primary" onClick={() => {this.addDoctor();}}>
                  Submit
              </Button>
            </form>
            </div>
        );
    }
}

export default DoctorProfileCreate;