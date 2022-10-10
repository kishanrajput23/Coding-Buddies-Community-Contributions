import React, { Component } from 'react';
import NavigationPatient from '../navBars/NavigationPatient'
import {Form,Button} from 'react-bootstrap'
import AllPatientDetailsServices from '../../services/AllPatientDetailsServices'

class PatientProfileUpdate extends Component {
    constructor(props) {
        super(props)
        this.state = {
            id:this.props.match.params.id,
            age:null,
            email:"",
            name:"",
            mobile:"",
            height:null,
            weight:null,
            errors: {}
        }
        AllPatientDetailsServices.getPatient(this.props.match.params.id)
        .then(res=>{
            this.setState({age:res.data.patientAge,
            name: res.data.patientName,
            email: res.data.patientEmail,
            mobile: res.data.patientMobile,
            weight: res.data.patientWeight,
            height: res.data.patientHeight})    
        })
        // this.changeIdHandler = this.changeIdHandler.bind(this);
        this.changeAgeHandler = this.changeAgeHandler.bind(this);
        this.changeEmailHandler = this.changeEmailHandler.bind(this);
        this.changeNameHandler = this.changeNameHandler.bind(this);
        this.changeMobileHandler = this.changeMobileHandler.bind(this);
        this.changeHeightHandler = this.changeHeightHandler.bind(this);
        this.changeWeightHandler = this.changeWeightHandler.bind(this);
        this.updatePatient = this.updatePatient.bind(this);
    }

    handleValidation(){
        let age = this.state.age;
        let email = this.state.email;
        let name = this.state.name;
        let mobile = this.state.mobile;
        let height = this.state.height;
        let weight = this.state.weight;
        let errors = {};
        let formIsValid = true;

        //Age
        if(!age){
           formIsValid = false;
           errors["age"] = "Cannot be empty";
        }
  
        if(typeof age !== "undefined"){
            if(age<1 || age>110){
              formIsValid = false;
              errors["age"] = "Should be between 1 and 110";
            }         
        }

        //Email
        if(!email){
            formIsValid = false;
            errors["email"] = "Cannot be empty";
         }
   
         if(typeof email !== "undefined"){
             if(email.length<1 || email.length>30){
               formIsValid = false;
               errors["email"] = "Should be between 1 and 30 characters";
             }       
             if(!email.match(/^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/)){
                 formIsValid = false;
                 errors["email"] = "Invalid email";
              }    
         }

         //Mobile
        if(!mobile){
            formIsValid = false;
            errors["mobile"] = "Cannot be empty";
         }
   
         if(typeof mobile !== "undefined"){
             if(mobile.length!==10){
               formIsValid = false;
               errors["mobile"] = "Should be 10 digits";
             }       
             if(!mobile.match(/^[0-9]*$/)){
                 formIsValid = false;
                 errors["mobile"] = "Please enter only digits";
              }    
         }

         //Name
        if(!name){
            formIsValid = false;
            errors["name"] = "Cannot be empty";
         }
   
         if(typeof name !== "undefined"){
             if(name.length<1 || name.length>100){
               formIsValid = false;
               errors["name"] = "Should be between 1 and 100 characters";
             }       
             if(!name.match(/^[a-zA-Z ]*$/)){
                 formIsValid = false;
                 errors["name"] = "Please enter only Alphabets";
              }    
         }

         //Height
        if(!height){
            formIsValid = false;
            errors["height"] = "Cannot be empty";
         }
   
         if(typeof height !== "undefined"){
             if(height<10 || height>300){
               formIsValid = false;
               errors["height"] = "Should be between 10 and 300 cm";
             }          
         }

         //Weight
        if(!weight){
            formIsValid = false;
            errors["weight"] = "Cannot be empty";
         }
   
         if(typeof weight !== "undefined"){
             if(weight<3 || weight>500){
               formIsValid = false;
               errors["weight"] = "Should be between 3 and 500 kg";
             }          
         }

       this.setState({errors: errors});
       return formIsValid;
          }
    
      changeAgeHandler= (event) => {
        this.setState({age: event.target.value});
        console.log(this.state.age);
      }
    
      changeEmailHandler= (event) => {
        this.setState({email: event.target.value});
        console.log(this.state.email)
      }
      
      changeNameHandler= (event) => {
        this.setState({name: event.target.value});
        console.log(this.state.name)
      }
      
      changeMobileHandler= (event) => {
        this.setState({mobile: event.target.value});
        console.log(this.state.mobile)
      }
      
      changeHeightHandler= (event) => {
        this.setState({height: event.target.value});
        console.log(this.state.height)
      }

      changeWeightHandler= (event) => {
        this.setState({weight: event.target.value});
        console.log(this.state.weight)
      }
    updatePatient = () => {
        let p={patientId: this.state.id, patientEmail: this.state.email, patientName: this.state.name, patientMobile: this.state.mobile, patientAge: this.state.age, patientHeight: this.state.height, patientWeight: this.state.weight};
        console.log('p =>' + JSON.stringify(p));
        if(this.handleValidation()){
            AllPatientDetailsServices.postPatient(p).then( res => {
                console.log(res);
                window.location='http://localhost:3000/patient/'+res.data.patientId;
            });
            alert("Form submitted");
         }
    }
    render() {
        return (
            <div>
               <NavigationPatient/>
               <form className="container mt-4" style={{textAlign:'left'}}>
                <h3>Update your profile</h3>
                <Form.Group >
                  <Form.Label>Patient Id</Form.Label>
                  <Form.Control type="text" value={this.state.id}/>
                  <span style={{color: "red"}}>{this.state.errors["name"]}</span>           
              </Form.Group>
                <Form.Group >
                  <Form.Label>Name</Form.Label>
                  <Form.Control type="text" onChange={this.changeNameHandler} value={this.state.name} placeholder="Enter your name"/>
                  <span style={{color: "red"}}>{this.state.errors["name"]}</span>           
              </Form.Group>
              <Form.Group >
                  <Form.Label>Age</Form.Label>
                  <Form.Control type="number" onChange={this.changeAgeHandler} value={this.state.age} placeholder="Enter your age"/>           
                  <span style={{color: "red"}}>{this.state.errors["age"]}</span>  
              </Form.Group>
              <Form.Group >
                  <Form.Label>Email ID</Form.Label>
                  <Form.Control type="email" onChange={this.changeEmailHandler} value={this.state.email} placeholder="Enter your email id"/>           
                  <span style={{color: "red"}}>{this.state.errors["email"]}</span>  
              </Form.Group>
              <Form.Group >
                  <Form.Label>Mobile Number</Form.Label>
                  <Form.Control type="text" onChange={this.changeMobileHandler} value={this.state.mobile} placeholder="Enter your mobile number"/>           
                  <span style={{color: "red"}}>{this.state.errors["mobile"]}</span>  
              </Form.Group>
              <Form.Group >
                  <Form.Label>Height</Form.Label>
                  <Form.Control type="number" onChange={this.changeHeightHandler} value={this.state.height} placeholder="Enter your height"/>           
                  <span style={{color: "red"}}>{this.state.errors["height"]}</span>  
              </Form.Group>
              <Form.Group >
                  <Form.Label>Weight</Form.Label>
                  <Form.Control type="number" onChange={this.changeWeightHandler} value={this.state.weight} placeholder="Enter your weight"/>           
                  <span style={{color: "red"}}>{this.state.errors["weight"]}</span>  
              </Form.Group>

              <Button variant="primary" onClick={() => {this.updatePatient();}}>
                  Submit
              </Button>
            </form>
            </div>
        );
    }
}

export default PatientProfileUpdate;