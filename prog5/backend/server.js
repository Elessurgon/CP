const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
const cors = require('cors');

const Inventory = require('./model/inventory');

const app = express();

const PORT = 5000;

app.use(bodyParser.json());
app.use(cors());

app.get('/', async (req, res) => {
  let inventory;

  try {
    inventory = await Inventory.find();
  }catch (err) {
    console.log(err);
    return res.send('Error occurred while fetching the data');
  }

  res.json({ inventory });
})

app.post('/', async (req, res) => {
  const inv = req.body;

  const newInv = new Inventory({
    name: inv.name,
    itemPrice: inv.itemPrice,
    itemId: inv.itemId,
    itemDescription: inv.itemDescription,
  });

  try {
    await newInv.save();
  } catch(err) {
    console.log(err);
    return res.send('Error occurred while saving the item');
  }

  res.json({ newInv });
})


mongoose.connect('mongodb://localhost:27017/Inventory', () => {
  app.listen(PORT, () => {
    console.log(`Server started on port number ${PORT} and Database connected`);
  });
})

