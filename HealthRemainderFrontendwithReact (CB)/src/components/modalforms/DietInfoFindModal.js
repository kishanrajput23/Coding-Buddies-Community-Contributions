import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import React, { Component } from 'react'
import { Link, withRouter } from 'react-router-dom';

class DietInfoFindModal extends Component {
  constructor(props) {
    super(props)

    this.state = {
        bmi: null,
        errors: {}
    }
    this.changeBmiHandler = this.changeBmiHandler.bind(this);
    this.findDiet = this.findDiet.bind(this);
  }

  handleValidation(){
    let bmi = this.state.bmi;
    let errors = {};
    let formIsValid = true;

    //BMI
    if(!bmi){
       formIsValid = false;
       errors["bmi"] = "Cannot be empty";
    }

    if(typeof bmi !== "undefined"){
        if(bmi<1 || bmi>4){
          formIsValid = false;
          errors["bmi"] = "Should be between 1 and 4";
        }        
    }

   this.setState({errors: errors});
   return formIsValid;
  }

  changeBmiHandler= (event) => {
        this.setState({bmi: event.target.value});    
  }

  findDiet = () => {
    console.log('BMI =>' + JSON.stringify(this.state.bmi));
    if(this.handleValidation()){
        window.location = "/DietInfoView/"+this.state.bmi;
        // window.open("/DietInfoView/"+this.state.bmi);
     }else{
        alert("Form has errors.")
     }
  }
  
  render(){
    return(
        <div>
      <Modal 
        show={this.props.isOpen} 
        onHide={this.props.closeModal}
      >
      <Modal.Header closeButton>
        <Modal.Title>Get Diet Plan</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <h6>1: Underweight = less than 18.5</h6>
          <h6>2: Normal weight = 18.5 - 24.9</h6>
          <h6>3: Overweight = 25 - 29.9</h6>
          <h6>4: Obesity = greater than 30</h6>
          <Form.Group >
              <Form.Label>Patient BMI </Form.Label>
              <Form.Control type="number" onChange={this.changeBmiHandler} value={this.state.bmi} placeholder="Enter Patient BMI"/>           
              <span style={{color: "red"}}>{this.state.errors["bmi"]}</span>           
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
        <Link  className="btn btn-primary" onClick={() => {this.findDiet();}}>Submit</Link>
      </Modal.Footer>
    </Modal>
    </div>
    )
  }
}

export default withRouter(DietInfoFindModal);