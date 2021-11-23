const mongoose = require('mongoose')

const Music = new mongoose.Schema({
    name : {type : String, required: true},
    song : {type : String, required: true},
    date: {type: Date, require: true},
    album: String,
    singers: [String]
})

module.exports = mongoose.model('Music', Music)