import React, { Component } from 'react'
import DietListServices from '../../services/DietListServices'
import NavigationPatient from '../navBars/NavigationPatient'

class DietInfoView extends Component {
    constructor(props) {
        super(props)

        this.state = {
            bmi: this.props.match.params.bmi,
            diet: {}
        }
    }

    componentDidMount(){
        console.log(this.state.bmi);
            DietListServices.findInfo(this.state.bmi).then( res => {
                this.setState({diet: res.data});
             })
    }

    render() {
        return (
            <div>
                <NavigationPatient/>
            <div>
                <br></br>
                <div className = "card col-md-6 offset-md-3">
                    <h3 className = "text-center"> View Diet Plan</h3>
                    <div className = "card-body">
                        <div className = "row">
                            <label> Patient BMI:  </label>
                            <div> { this.state.diet.bmiValue}</div>
                        </div>
                        <div className = "row">
                            <label> Diet Plan:  </label>
                            <div> { this.state.diet.diet}</div>
                        </div>
                    </div>

                </div>
            </div>
        </div>
        )
    }
}


export default DietInfoView;