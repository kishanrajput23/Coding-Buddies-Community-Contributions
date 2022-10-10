import React from 'react';
import DietListServices from '../../services/DietListServices';
import NavigationAdmin from '../navBars/NavigationAdmin';
import DietInfoUpdateModal from '../modalforms/DietInfoUpdateModal';
import DietInfoAddModal from '../modalforms/DietInfoAddModal';
import DietInfoDeleteModal from '../modalforms/DietInfoDeleteModal';

class DietList extends React.Component{
    constructor(props){
        super(props)
        this.state={
            dietInfo:[]
        }   
        this.changeBmiHandler=this.changeBmiHandler.bind(this);     
    }

    state = {
        isOpen: false,
        isAddOpen: false,
        isDeleteOpen: false,
        bmi: null,
      }      
    
      openModal = () => this.setState({ isOpen: true });
      closeModal = () => {this.setState({ isOpen: false }); }  

      openAddModal = () => this.setState({ isAddOpen: true });
      closeAddModal = () => {this.setState({ isAddOpen: false }); }

      openDeleteModal = () => this.setState({ isDeleteOpen: true });
      closeDeleteModal = () => {this.setState({ isDeleteOpen: false }); }

      changeBmiHandler= (e) => {
        this.setState({bmi: e});
        console.log(this.state.bmi);
      }
      
    componentDidMount(){
        DietListServices.viewInfo().then((response) => {
            console.log(response);
            this.setState({dietInfo :response.data})
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
                    <h3 className="font-weight-bold"> Diet Information</h3>
                    <div className="row">
                        <button className="btn btn-info" onClick= {this.openAddModal}>Add Diet Plan</button>
                    </div>
                    <p> </p>
                    <table className="table table-hover table-bordered">
                        <thead>
                            <tr>
                                <th> BMI</th>
                                <th> Diet</th>
                                <th> Actions</th>
                            </tr>
                        </thead>

                        <tbody>
                           {
                               this.state.dietInfo.map(
                                DietInformation =>
                                   <tr key = {DietInformation.bmiValue}>
                                       <td> {DietInformation.bmiValue}</td> 
                                       <td> {DietInformation.diet}</td>
                                       <td>
                                       <button className="btn btn-outline-info" 
                                              onClick={() => {this.changeBmiHandler(DietInformation.bmiValue); this.openModal();}} >
                                                  Update</button>
                                {' '} <button className="btn btn-outline-info" 
                                               onClick={() => {this.changeBmiHandler(DietInformation.bmiValue); this.openDeleteModal();}}>
                                               Delete</button>
                                        </td>
                                   </tr>
                               )
                           }
                        </tbody>
                    </table>
                </div>
                { this.state.isAddOpen ?   
                                                <DietInfoAddModal 
                                                closeAddModal={this.closeAddModal} 
                                                isAddOpen={this.state.isAddOpen} 
                                                addDiet={this.addInfo} 
                                                /> : null 
                                            }
                { this.state.isOpen ?   
                                                <DietInfoUpdateModal 
                                                closeModal={this.closeModal} 
                                                isOpen={this.state.isOpen} 
                                                updateDiet={this.updateInfo} bmi={this.state.bmi}
                                                changeHere={this.changeHere}
                                                /> : null 
                                            }
                                             { this.state.isDeleteOpen ?   
                                                <DietInfoDeleteModal
                                                closeDeleteModal={this.closeDeleteModal} 
                                                isDeleteOpen={this.state.isDeleteOpen} 
                                                deleteDiet={this.deleteInfo} bmi={this.state.bmi} 
                                                /> : null 
                                            }
            </div>
        )
    }

}

export default DietList;