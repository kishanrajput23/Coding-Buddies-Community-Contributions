import React from 'react';
import MentalListServices from '../../services/MentalListServices';
import NavigationAdmin from '../navBars/NavigationAdmin';
import ModalForm from '../modalforms/ModalForm';
import MentalAddModal from '../modalforms/MentalAddModal';
import MentalDeleteModal from '../modalforms/MentalDeleteModal';

class MentalList extends React.Component{
    constructor(props){
        super(props)
        this.state={
            healthtips:[]
        }    
        this.changeRatingHandler=this.changeRatingHandler.bind(this);    
    }

    state = {
        isOpen: false,
        isAddOpen: false,
        isDeleteOpen: false,
        id: null,
      }      
    
      openModal = () => this.setState({ isOpen: true });
      closeModal = () => {this.setState({ isOpen: false }); }  
      
      openAddModal = () => this.setState({ isAddOpen: true });
      closeAddModal = () => {this.setState({ isAddOpen: false }); }
      
      openDeleteModal = () => this.setState({ isDeleteOpen: true });
      closeDeleteModal = () => {this.setState({ isDeleteOpen: false }); }

      changeRatingHandler= (e) => {
        this.setState({id: e});
        console.log(this.state.id);
      }
      
    componentDidMount(){
        MentalListServices.viewTips().then((response) => {
            console.log(response);
            this.setState({healthtips :response.data})
        });
    }

    render(){
        return(
            <div>
                <div>
                     <NavigationAdmin />
                </div>
                <p> </p>
                <div className="container">
                    <h3 className="font-weight-bold"> Mental Health Tips</h3>
                    <div className="row">
                        <button className="btn btn-info" onClick= {this.openAddModal}>Add Health Tip</button>
                    </div>
                    <p> </p>
                    <table className="table table-hover table-bordered">
                        <thead>
                            <tr>
                                <th> Health Scale</th>
                                <th> Health Tip</th>
                                <th> Actions</th>
                            </tr>
                        </thead>

                        <tbody>
                           {
                               this.state.healthtips.map(
                                MentalHealth =>
                                   <tr key = {MentalHealth.mentalRating}>
                                       <td> {MentalHealth.mentalRating}</td> 
                                       <td> {MentalHealth.mentalTip}</td>
                                       <td>
                                      <button className="btn btn-outline-info" 
                                              onClick={() => {this.changeRatingHandler(MentalHealth.mentalRating); this.openModal();}} >
                                                  Update</button>
                                {' '} <button className="btn btn-outline-info" 
                                              onClick={() => {this.changeRatingHandler(MentalHealth.mentalRating); this.openDeleteModal();}}>
                                                  Delete</button>
                                        </td>
                                   </tr>
                               )
                           }
                        </tbody>
                    </table>
                </div>
                { this.state.isAddOpen ?   
                                                <MentalAddModal 
                                                closeAddModal={this.closeAddModal} 
                                                isAddOpen={this.state.isAddOpen} 
                                                addTips={this.addTips} 
                                                /> : null 
                                            }
                { this.state.isOpen ?   
                                                <ModalForm 
                                                closeModal={this.closeModal} 
                                                isOpen={this.state.isOpen} 
                                                updateTips={this.updateTips} id={this.state.id} 
                                                /> : null 
                                            }
                { this.state.isDeleteOpen ?   
                                                <MentalDeleteModal
                                                closeDeleteModal={this.closeDeleteModal} 
                                                isDeleteOpen={this.state.isDeleteOpen} 
                                                deleteTips={this.deleteTips} id={this.state.id} 
                                                /> : null 
                                            }
                
            </div>
        )
    }

}

export default MentalList;