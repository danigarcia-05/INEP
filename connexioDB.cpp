#include "connexioDB.h"


// Inicialització del punter estàtic
ConnexioDB* ConnexioDB::_ins = nullptr;

ConnexioDB& ConnexioDB::getInstance() {
    if (_ins == nullptr) {
        _ins = new ConnexioDB();
    }
    return *_ins;
}

ConnexioDB::ConnexioDB() : driver(nullptr), con(nullptr), stmt(nullptr) {
    // Llegeix el fitxer de configuració
    map<string, string> config = loadConfig("config.txt");

    string db_host = config["db_host"];
    string db_port = config["db_port"];
    string db_user = config["db_user"];
    string db_password = config["db_password"];
    string db_name = config["db_name"];

    // Configura la connexió a la base de dades
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(db_host + ":" + db_port, db_user, db_password);
    con->setSchema(db_name);
    stmt = con->createStatement();
}

ConnexioDB::~ConnexioDB() {
    if (stmt) delete stmt;
    if (con) {
        con->close();
        delete con;
    }
}

sql::ResultSet* ConnexioDB::consultaSQL(const string& sql) {
    if (stmt != nullptr) {
        return stmt->executeQuery(sql);
    }
    return nullptr;
}

void ConnexioDB::executarSQL(const string& sql) {
    if (stmt != nullptr) {
        stmt->execute(sql);
    }
}

// Funció per carregar la configuració des d'un fitxer
map<string, string> ConnexioDB::loadConfig(const string& filename) {
    ifstream config_file(filename);
    if (!config_file.is_open()) {
        throw runtime_error("ArxiuNoExisteix");
    }

    map<string, string> config;
    string line;
    while (getline(config_file, line)) {
        istringstream line_stream(line);
        string key, value;
        if (getline(line_stream, key, '=') && getline(line_stream, value)) {
            config[key] = value;
        }
    }
    return config;
}
