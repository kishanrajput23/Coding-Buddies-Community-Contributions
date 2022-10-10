import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import Button from 'react-bootstrap/button'
import React, { Component } from 'react'
import { withRouter } from 'react-router-dom';
import MentalListServices from '../../services/MentalListServices'


class ModalForm extends Component {
  constructor(props) {
    super(props)

    this.state = {
      //  id:null,
        tip:"",
        errors: {}
    }
   // this.changeRatingHandler = this.changeRatingHandler.bind(this);
    this.changeTipHandler = this.changeTipHandler.bind(this);
    this.updateTips = this.updateTips.bind(this);
}

  // changeRatingHandler= (event) => {
  //   this.setState({id: event.target.value});
  //   console.log(this.state.id);
  // }

  handleValidation(){
    let tip = this.state.tip;
    let errors = {};
    let formIsValid = true;

    //Tip
    if(!tip){
       formIsValid = false;
       errors["tip"] = "Cannot be empty";
    }

    if(typeof tip !== "undefined"){
        if(tip.length<5 || tip.length>200){
          formIsValid = false;
          errors["tip"] = "Should be between 5 and 200 characters";
        }       
        if(!tip.match(/.*[a-zA-Z]+.*/)){
            formIsValid = false;
            errors["tip"] = "Please enter atleast one Alphabet";
         }    
    }

   this.setState({errors: errors});
   return formIsValid;
}

  changeTipHandler= (event) => {
    this.setState({tip: event.target.value});
    console.log(this)

  }

  updateTips = () => {
    //e.preventDefault();
    console.log('id => ' + JSON.stringify(this.props.id));
    if(this.handleValidation()){
      MentalListServices.updateTips(this.props.id, this.state.tip).then( res => {
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
        <Modal.Title>Update Health Tip</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <Form.Group >
              <Form.Label>Content </Form.Label>
              <Form.Control type="text" onChange={this.changeTipHandler} value={this.state.tip} placeholder="Enter a Tip"/> 
              <span style={{color: "red"}}>{this.state.errors["tip"]}</span>             
          </Form.Group>
          <Form.Group>
            <div> Are you sure you want to Update Tip {this.props.id}?</div>
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
          <Button variant="primary" type="submit" onClick={() => {this.updateTips();}}>
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

export default withRouter(ModalForm);