import React from 'react';
import axios from 'axios';

import './App.css';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      inventory: [],
      selectedInventory: null,
    };
  }

  componentDidMount = () => {
    axios.get('http://localhost:5000/').then(res => {
      this.setState(() => ({
        inventory: res.data.inventory,
      }));
    }).catch(err => {
      console.log(err);
    });
  }

  viewItem = (itemId) => {
    const item = this.state.inventory.find(item => item.itemId === itemId);

    if (item) {
      this.setState(() => ({
        selectedInventory: item,
      }))
    }
  }

  removeItem = () => {
    this.setState(() => ({
      selectedInventory: null,
    }))
  }

  render() {
    return (
      <div className="wrapper">
        <h1>List of items from Inventory</h1>

        <hr />

        <table border={2} cellPadding={2} cellSpacing={2}>
          <thead>
            <th>Item Id</th>
            <th>Item Name</th>
            <th>Item Price</th>
            <th>Item Description</th>
            <th>Actions</th>
          </thead>
          <tbody>
            {this.state.inventory.map((item) => {
              return (
                <tr key={item.itemId}>
                  <td>{item.itemId}</td>
                  <td>{item.name}</td>
                  <td>{item.itemPrice}</td>
                  <td>{item.itemDescription}</td>
                  <td className='view-btn' onClick={() => this.viewItem(item.itemId)}>
                    View
                  </td>
                </tr>
              )
            })}
          </tbody>
        </table>

        <hr />
        
        <div onClick={() => this.removeItem()}>
          {this.state.selectedInventory && (
            <pre className="inventory-details">
              {JSON.stringify(this.state.selectedInventory, null, 2)}
            </pre>
          )}
        </div>
      </div>
    );
  }
}

export default App;
