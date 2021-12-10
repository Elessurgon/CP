const mongoose = require('mongoose');

const Inventory = mongoose.Schema({
  name: String,
  itemPrice: Number,
  itemId: Number,
  itemDescription: String,
});

module.exports = mongoose.model('Inventory', Inventory);
