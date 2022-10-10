import React,{Component} from 'react'
import DoctorNavigation from '../navBars/DoctorNavigation';
import AllDoctorDetailsServices from '../../services/AllDoctorDetailsServices';
import {Form,Button} from 'react-bootstrap'

class DoctorProfileUpdate extends Component{
    constructor(props) {
        super(props)
    
        this.state = {
            doctorId:this.props.match.params.id,
            verfStatus:true,
            doctorSpec:"",
            doctorCertFile:"Certified",
            doctorName:"",
            errors: {}
        }
        console.log(this.state)
        // this.changeIdHandler = this.changeIdHandler.bind(this);
        this.changeDoctorNameHandler = this.changeDoctorNameHandler.bind(this);
        this.changeDoctorSpecHandler = this.changeDoctorSpecHandler.bind(this);
        this.updateDoctor = this.updateDoctor.bind(this);
    }
    componentDidMount(){
        AllDoctorDetailsServices.getDoctorById(this.props.match.params.id)
        .then(res=>{
            this.setState({doctorName:res.data.doctorName,doctorSpec:res.data.doctorSpec})
        })
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
      updateDoctor = () =>{
        AllDoctorDetailsServices.updateDoctor(this.state.doctorId,this.state.doctorName,this.state.doctorSpec)
        .then(res=>{
            console.log(res)
            window.location='http://localhost:8086/healthreminder/doctor'
        })
    }
    
    render(){
        return(
            <>
            <DoctorNavigation/>
            <form className="container mt-4" style={{textAlign:'left'}}>
                <h3>Setup your profile</h3>
                <Form.Group >
                  <Form.Label>Doctor Specialization</Form.Label>
                  <Form.Control type="text" onChange={this.changeDoctorSpecHandler} value={this.state.doctorSpec} placeholder="Enter your Specialization"/>
                  <span style={{color: "red"}}>{this.state.errors["doctorSpec"]}</span>           
              </Form.Group>
              <Form.Group >
                  <Form.Label>Doctor Name</Form.Label>
                  <Form.Control type="text" onChange={this.changeDoctorNameHandler} value={this.state.doctorName} placeholder="Enter your Name"/>           
                  <span style={{color: "red"}}>{this.state.errors["doctorName"]}</span>  
              </Form.Group>
              <Button variant="primary" onClick={() => {this.updateDoctor();}}>
                  Submit
              </Button>
            </form>
            </>
        );
    }
}

export default DoctorProfileUpdate;