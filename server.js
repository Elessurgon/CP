const express = require('express')
const cors = require('cors')
const mongoose = require('mongoose')


const app = express()
app.use(express.json())
const musicRoutes = require('./routes/music')

const port = 8080
const MongoDBUrl = 'mongodb+srv://russel:abcd1234@music.7tkb7.mongodb.net/myFirstDatabase?retryWrites=true&w=majority'




app.use(express.urlencoded({extends: true}))
app.use(cors())


app.use('/api/music/', musicRoutes)

mongoose.connect(MongoDBUrl, () => {
    app.listen(port, () => {
        console.log(`server is at ${port}`)
    })
})