const multer = require('multer')

const storage = multer.diskStorage({
    destination: (req, res, callback) => {
        callback(null, './upload/music')
    },
    filename: (req, file, callback) => {
        callback(null, file.originalname)
    }
})

const upload = multer({ storage })

module.exports = { upload }