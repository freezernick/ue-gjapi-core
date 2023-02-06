module.exports.readVersion = function (contents) {
    return JSON.parse(contents).VersionName;
};

module.exports.writeVersion = function (contents, version) {
    const json = JSON.parse(contents);
    json.VersionName = version;
    json.Version += 1;
    return JSON.stringify(json, null, 4);
};