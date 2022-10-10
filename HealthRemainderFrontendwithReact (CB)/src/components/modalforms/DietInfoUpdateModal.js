import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import Button from 'react-bootstrap/button'
import React, { Component } from 'react'
import { withRouter } from 'react-router-dom';
import DietListServices from '../../services/DietListServices'


class DietInfoUpdateModal extends Component {
  constructor(props) {
    super(props)

    this.state = {
        // bmi:null,
        diet:"",
        errors: {}
    }
    // this.changeBmiHandler = this.changeBmiHandler.bind(this);
    this.changeDietHandler = this.changeDietHandler.bind(this);
    this.updateDiet = this.updateDiet.bind(this);
}

  // changeBmiHandler= (event) => {
  //   this.setState({bmi: event.target.value});
  //   console.log(this.state.bmi);
  // }

  handleValidation(){
    let diet = this.state.diet;
    let errors = {};
    let formIsValid = true;

    //Diet
    if(!diet){
       formIsValid = false;
       errors["diet"] = "Cannot be empty";
    }

    if(typeof diet !== "undefined"){
        if(diet.length<5 || diet.length>200){
          formIsValid = false;
          errors["diet"] = "Should be between 5 and 200 characters";
        }   
        if(!diet.match(/^(?=.*[\w\d]).+/)){
          formIsValid = false;
          errors["diet"] = "Should have atleast 1 alphabet or digit";
       }         
    }

   this.setState({errors: errors});
   return formIsValid;
}
  changeDietHandler= (event) => {
    this.setState({diet: event.target.value});
    console.log(this)

  }

  updateDiet = () => {
    //e.preventDefault();
    console.log('bmi => ' + JSON.stringify(this.props.bmi));
    if(this.handleValidation()){
      DietListServices.updateInfo(this.props.bmi, this.state.diet).then( res => {
        console.log(res);
        window.location.reload();
    });
      alert("Form submitted");
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
        <Modal.Title>Update Diet Plan</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          {/* <Form.Group >
              <Form.Label>BMI </Form.Label>
              <Form.Control type="number" onChange={this.changeBmiHandler} value={this.state.bmi} placeholder="BMI input"/>           
          </Form.Group> */}
          <Form.Group >
              <Form.Label>Diet </Form.Label>
              <Form.Control type="text" onChange={this.changeDietHandler} value={this.state.diet} placeholder="Enter the diet"/>           
              <span style={{color: "red"}}>{this.state.errors["diet"]}</span>           
          </Form.Group>
          <Form.Group>
            <div> Are you sure you want to Update Diet {this.props.bmi}?</div>
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
          <Button variant="primary" type="submit" onClick={() => {this.updateDiet();}}>
              Yes
          </Button>
          <Button variant="primary"  onClick={() => {this.props.closeModal()}}>
                  No
              </Button>
      </Modal.Footer>
    </Modal>
    </div>
    )
  }
}

export default withRouter(DietInfoUpdateModal);